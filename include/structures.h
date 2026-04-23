#ifndef STRUCTURES_H
# define STRUCTURES_H

// TODO: 구조체 정리 필요. 

typedef struct s_vec3 t_vec3;
typedef struct s_vec3 t_point3;
typedef struct s_vec3 t_color3;
typedef struct s_hit_record t_hit_record;
typedef struct s_object t_object;
typedef struct s_sphere t_sphere;
typedef struct s_plane t_plane;
typedef struct s_cylinder t_cylinder;
typedef struct s_light t_light;

#define FALSE 0
#define TRUE 1
#define EPSILON 1e-6 // 부동소수점 오차를 고려한 값 0.000001
#define LUMEN 3 // 광원 밝기 계수
#define SAMPLES_PER_PIXEL 10 // SPP 100은 미니RT성능상 너무 느리므로 우선 10정도로 타협함

typedef int t_bool;
typedef int t_object_type;

typedef enum e_object_type 
{
	SP,
	LIGHT_POINT,
	PL,
	CY
}	t_object_type;

/* 수학 & 기초 core */

struct s_vec3
{
	double x;
	double y;
	double z;
};

typedef struct s_ray
{
	t_point3 orig;
	t_vec3 dir;
}	t_ray;

typedef struct s_camera
{
	t_point3	orig; // 카메라 원점(위치)
	double		viewport_h; // 뷰포트 세로
	double		viewport_w; // 가로
	t_vec3		horizontal; // 수평 길이 벡터
	t_vec3		vertical; // 수직 길이 벡터
	double		focal_len; // 뷰포트 중심과 관찰자까지의 z 거리
	t_point3	left_bottom; // 뷰포트와 관찰자와의 거리 관련된 좌표
}	t_camera;

typedef struct s_canvas
{
	int width;
	int height;
	double aspect_ratio; // 가로 세로비
}	t_canvas;

/* 렌더링할 오브젝트 */

typedef struct s_sphere
{
	t_point3 center;
	double radius;
	double radius2; // 제곱?
}	t_sphere;

typedef struct s_plane
{
	t_point3 point;
	t_vec3 normal_v;
} t_plane;

typedef struct s_cylinder
{
	t_point3 center;
	t_vec3 dir;
	double radius;
	double height;
} t_cylinder;

/* ======================== */

typedef struct s_light
{
	t_point3 origin;
	t_color3 light_color;
	double bright_ratio;
} t_light;

typedef struct s_hit_record
{
	t_point3	p; // 교점
	t_vec3		normal; // 교점에서의 법선
	double		tmin; // 오브젝트가 카메라의 뒤에 있거나(t< 0)
	double		tmax; // 오브젝트가 캄제라로부터 너무 멀 경우를 고려하기 위한 값들
	double		t; // 광선의 원점과 교점 사이의 거리
	t_bool		front_face;
	t_color3	albedo; // 물체가 가진 고유의 색, 빛을 반사하는 비율
}		t_hit_record;

typedef struct	s_object
{
	t_object_type	type;
	void			*element;
	void			*next;
	t_color3		albedo;
}				t_object;

typedef struct s_scene
{
	t_canvas		canvas;
	t_camera		camera;
	t_object		*world;
	t_object		*light;
	t_color3		ambient;
	t_ray			ray;
	t_hit_record	rec;
} t_scene;

#endif