package ray

import (
	"github.com/thescripted/sandbox-raytracing/vector"
)

type Ray struct {
	A vector.Vec3
	B vector.Vec3
}

func (r Ray) Origin() vector.Vec3 {
	return r.A
}

func (r Ray) Direction() vector.Vec3 {
	return r.B
}

func (r Ray) PointAtParameter(t float64) vector.Vec3 {
	return r.A.Add(r.B.Scale(t))
}