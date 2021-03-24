; ModuleID = 'seashell-compiler-output'
source_filename = "seashell-compiler-output"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1

; Function Attrs: noinline nounwind optnone
define i32* @read_ints(i32* %final_len) #0 {
entry:
  %final_len.addr = alloca i32*, align 8
  %len = alloca i32, align 4
  %maxlen = alloca i32, align 4
  %data = alloca i32*, align 8
  store i32* %final_len, i32** %final_len.addr, align 8
  store i32 0, i32* %len, align 4
  store i32 1, i32* %maxlen, align 4
  %0 = load i32, i32* %maxlen, align 4
  %conv = sext i32 %0 to i64
  %mul = mul i64 %conv, 4
  %call = call noalias i8* @malloc(i64 %mul) #3
  %1 = bitcast i8* %call to i32*
  store i32* %1, i32** %data, align 8
  br label %while.body

while.body:                                       ; preds = %entry, %if.end10
  %2 = load i32, i32* %len, align 4
  %3 = load i32, i32* %maxlen, align 4
  %cmp = icmp eq i32 %2, %3
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %while.body
  %4 = load i32, i32* %maxlen, align 4
  %mul2 = mul nsw i32 %4, 2
  store i32 %mul2, i32* %maxlen, align 4
  %5 = load i32*, i32** %data, align 8
  %6 = bitcast i32* %5 to i8*
  %7 = load i32, i32* %maxlen, align 4
  %conv3 = sext i32 %7 to i64
  %mul4 = mul i64 %conv3, 4
  %call5 = call i8* @realloc(i8* %6, i64 %mul4) #3
  %8 = bitcast i8* %call5 to i32*
  store i32* %8, i32** %data, align 8
  br label %if.end

if.end:                                           ; preds = %if.then, %while.body
  %9 = load i32*, i32** %data, align 8
  %10 = load i32, i32* %len, align 4
  %idx.ext = sext i32 %10 to i64
  %add.ptr = getelementptr inbounds i32, i32* %9, i64 %idx.ext
  %call6 = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i64 0, i64 0), i32* %add.ptr)
  %cmp7 = icmp ne i32 %call6, 1
  br i1 %cmp7, label %if.then9, label %if.end10

if.then9:                                         ; preds = %if.end
  br label %while.end

if.end10:                                         ; preds = %if.end
  %11 = load i32, i32* %len, align 4
  %inc = add nsw i32 %11, 1
  store i32 %inc, i32* %len, align 4
  br label %while.body

while.end:                                        ; preds = %if.then9
  %12 = load i32, i32* %len, align 4
  %tobool = icmp ne i32 %12, 0
  br i1 %tobool, label %if.then11, label %if.else

if.then11:                                        ; preds = %while.end
  %13 = load i32*, i32** %data, align 8
  %14 = bitcast i32* %13 to i8*
  %15 = load i32, i32* %len, align 4
  %conv12 = sext i32 %15 to i64
  %mul13 = mul i64 %conv12, 4
  %call14 = call i8* @realloc(i8* %14, i64 %mul13) #3
  %16 = bitcast i8* %call14 to i32*
  store i32* %16, i32** %data, align 8
  br label %if.end15

if.else:                                          ; preds = %while.end
  %17 = load i32*, i32** %data, align 8
  %18 = bitcast i32* %17 to i8*
  call void @free(i8* %18) #3
  store i32* null, i32** %data, align 8
  br label %if.end15

if.end15:                                         ; preds = %if.else, %if.then11
  %19 = load i32, i32* %len, align 4
  %20 = load i32*, i32** %final_len.addr, align 8
  store i32 %19, i32* %20, align 4
  %21 = load i32*, i32** %data, align 8
  ret i32* %21
}

; Function Attrs: nounwind
declare noalias i8* @malloc(i64) #1

; Function Attrs: nounwind
declare i8* @realloc(i8*, i64) #1

declare i32 @__isoc99_scanf(i8*, ...) #2

; Function Attrs: nounwind
declare void @free(i8*) #1

attributes #0 = { noinline nounwind optnone "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-features"="+cx8,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-features"="+cx8,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-features"="+cx8,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"clang version 9.0.1 (https://github.com/llvm/llvm-project.git c1a0a213378a458fbea1a5c77b315c7dce08fd05)"}
!1 = !{i32 1, !"wchar_size", i32 4}
