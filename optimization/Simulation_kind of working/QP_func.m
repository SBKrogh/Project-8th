function func = QP_func(R,f)

func = @(x)((x')*R*x + f*x)
end