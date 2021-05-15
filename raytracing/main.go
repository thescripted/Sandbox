package main

import (
	"fmt"
	"math"
	"math/rand"

	"github.com/thescripted/sandbox-raytracing/vector"
	"github.com/thescripted/sandbox-raytracing/ray"
)


type Material interface {
	Scatter(ray ray.Ray, record HitRecord) (scattered ray.Ray, attenuation vector.Vec3, ok bool)
}

// Hitable is an interface for all objects that must react to rays.
type Hitable interface {
	Hit(ray ray.Ray, tMin, tMax float64) (HitRecord, bool)
}

type Objects []Sphere

type Metal struct {
	albedo vector.Vec3
}

type Lambertian struct {
	albedo vector.Vec3
}

type Camera struct {
	origin vector.Vec3
	lowerLeftCorner vector.Vec3
	horizontal vector.Vec3
	vertical vector.Vec3
}

// HitRecord contains recorded information about where an object was hit.
type HitRecord struct {
	t float64
	point vector.Vec3
	Normal vector.Vec3
	Material Material
}

// A Sphere is a spherical Hitable.
type Sphere struct {
	center vector.Vec3
	radius float64
	material Material
}

func (m Metal) Scatter(rayIn ray.Ray, record HitRecord) (scattered ray.Ray, attenuation vector.Vec3, ok bool) {
	reflected := Reflect(rayIn.Direction().Unit(), record.Normal)
	scattered = ray.Ray{
		A: record.point,
		B: reflected,
	}
	attenuation = m.albedo
	if scattered.Direction().Dot(record.Normal) > 0 {
		return scattered, attenuation, true
	}
	return ray.Ray{}, vector.Vec3{}, false
}

func (l Lambertian) Scatter(rayIn ray.Ray, record HitRecord) (scattered ray.Ray, attenuation vector.Vec3, ok bool) {
	target := record.point.Add(record.Normal).Add(RandInUnitSphere())
	scattered = ray.Ray{
		A: record.point,
		B: target.Sub(record.point),
	}
	attenuation = l.albedo
	return scattered, attenuation, true
}

func (s Sphere) Hit(ray ray.Ray, tMin, tMax float64) (HitRecord, bool) {
	oc := ray.Origin().Sub(s.center)
	a := ray.Direction().Dot(ray.Direction())
	b := 2.0 * oc.Dot(ray.Direction())
	c := oc.Dot(oc) - s.radius*s.radius
	discriminant := b*b - 4*a*c

	record := HitRecord{}
	if discriminant > 0 {
		root := (-b - math.Sqrt(discriminant))/(2*a)
		if root < tMax && root > tMin {
			record.t = root
			record.point = ray.PointAtParameter(record.t)
			record.Normal = record.point.Sub(s.center).Scale(1 / s.radius)
			record.Material = s.material
			return record, true
		}

		root = (-b + math.Sqrt(discriminant))/(2*a)
		if root < tMax && root > tMin {
			record.t = root
			record.point = ray.PointAtParameter(record.t)
			record.Normal = record.point.Sub(s.center).Scale(1 / s.radius)
			record.Material = s.material
			return record, true
		}
	}
	return record, false
}

func (o Objects) Hit(ray ray.Ray, tMin, tMax float64) (HitRecord, bool) {
	isHit := false
	globalRecord := HitRecord{}
	closest := tMax
	for _, sphere := range o {
		if record, ok := sphere.Hit(ray, tMin, closest); ok {
			isHit = true
			closest = record.t
			globalRecord = record
		}
	}
	return globalRecord, isHit
}

func (c Camera) GetRay(u, v float64) ray.Ray {
	return ray.Ray{
		A: c.origin,
		B: c.lowerLeftCorner.Add(c.horizontal.Scale(u)).Add(c.vertical.Scale(v)),
	}
}

func color(r ray.Ray, world Hitable, depth int) vector.Vec3 {
	if  record, ok := world.Hit(r, 0.001, 1000); ok {
		scattered, attenuation, ok := record.Material.Scatter(r, record)
		if depth < 50 && ok {
			return attenuation.Times(color(scattered, world, depth+1))
		} else {
			return vector.Vec3{0,0,0}
		}
	}
	unitDir := r.Direction().Unit()
	t := 0.5*(unitDir.Y() + 1)
	return vector.Vec3{1, 1, 1}.Scale(1 - t).Add(vector.Vec3{0.5, 0.7, 1}.Scale(t))

}

func main() {
	nx := 600
	ny := 300
	ns := 200
	fmt.Printf(
		"P3\n"+
			"%d %d\n"+
			"255\n", nx, ny,
	)

	camera := Camera{
		vector.Vec3{0, 0, 0},
		vector.Vec3{-2, -1, -1},
		vector.Vec3{4, 0, 0},
		vector.Vec3{0, 2, 0},
	}

	world := Objects{
		Sphere{center: vector.Vec3{0,0,-1}, radius: 0.35, material: Lambertian{vector.Vec3{0.8, 0.3, 0.3}}},
		Sphere{center: vector.Vec3{0,-25.5,-1}, radius: 25,  material: Lambertian{vector.Vec3{0.8, 0.8, 0.0}}},
		Sphere{center: vector.Vec3{1,0,-1}, radius: 0.5, material: Metal{vector.Vec3{0.8, 0.6, 0.2}}},
		Sphere{center: vector.Vec3{-1,0,-1}, radius: 0.5, material: Metal{vector.Vec3{0.8, 0.8, 0.8}}},
	}

	for j := ny - 1; j >= 0; j-- {
		for i := 0; i < nx; i++ {
			col := vector.Vec3{0,0,0}
			for s := 0; s < ns; s++ {
				u := (float64(i)) / float64(nx)
				v := (float64(j)) / float64(ny)
				ray := camera.GetRay(u, v)
				col = col.Add(color(ray, world, 0))
			}
			col = col.Scale(1.0/float64(ns))
			col = vector.Vec3{math.Sqrt(col.X()), math.Sqrt(col.Y()), math.Sqrt(col.Z())}
			ir := int(255.99 * col.X())
			ig := int(255.99 * col.Y())
			ib := int(255.99 * col.Z())
			fmt.Printf("%d %d %d\n", ir, ig, ib)

		}
	}
}

func RandInUnitSphere() vector.Vec3 {
	var p vector.Vec3
	for {
		p = vector.Vec3{rand.Float64(), rand.Float64(), rand.Float64()}.Scale(2).Sub(vector.Vec3{1, 1, 1})
		if p.LenSq() < 1 {
			break
		}
	}
	return p
}

func Reflect(v, n vector.Vec3) vector.Vec3 {
	return v.Sub(n.Scale(2 * n.Dot(v)))
}