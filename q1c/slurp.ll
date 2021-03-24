; ModuleID = 'seashell-compiler-output'
source_filename = "seashell-compiler-output"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [3 x i8] c"%c\00", align 1

; Function Attrs: noinline nounwind optnone
define i8* @slurp() #0 {
entry:
  %retval = alloca i8*, align 8
  %c = alloca i8, align 1
  %maxlen = alloca i32, align 4
  %len = alloca i32, align 4
  %s = alloca i8*, align 8
  store i8 0, i8* %c, align 1
  store i32 1, i32* %maxlen, align 4
  store i32 0, i32* %len, align 4
  %0 = load i32, i32* %maxlen, align 4
  %conv = sext i32 %0 to i64
  %mul = mul i64 %conv, 1
  %call = call noalias i8* @malloc(i64 %mul) #3
  store i8* %call, i8** %s, align 8
  br label %while.cond

while.cond:                                       ; preds = %if.end, %entry
  %call1 = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i64 0, i64 0), i8* %c)
  %cmp = icmp eq i32 %call1, 1
  br i1 %cmp, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %1 = load i32, i32* %len, align 4
  %2 = load i32, i32* %maxlen, align 4
  %cmp3 = icmp eq i32 %1, %2
  br i1 %cmp3, label %if.then, label %if.end

if.then:                                          ; preds = %while.body
  %3 = load i32, i32* %maxlen, align 4
  %mul5 = mul nsw i32 %3, 2
  store i32 %mul5, i32* %maxlen, align 4
  %4 = load i8*, i8** %s, align 8
  %5 = load i32, i32* %maxlen, align 4
  %conv6 = sext i32 %5 to i64
  %mul7 = mul i64 %conv6, 1
  %call8 = call i8* @realloc(i8* %4, i64 %mul7) #3
  store i8* %call8, i8** %s, align 8
  br label %if.end

if.end:                                           ; preds = %if.then, %while.body
  %6 = load i8, i8* %c, align 1
  %7 = load i8*, i8** %s, align 8
  %8 = load i32, i32* %len, align 4
  %idxprom = sext i32 %8 to i64
  %arrayidx = getelementptr inbounds i8, i8* %7, i64 %idxprom
  store i8 %6, i8* %arrayidx, align 1
  %9 = load i32, i32* %len, align 4
  %inc = add nsw i32 %9, 1
  store i32 %inc, i32* %len, align 4
  br label %while.cond

while.end:                                        ; preds = %while.cond
  %10 = load i32, i32* %len, align 4
  %tobool = icmp ne i32 %10, 0
  br i1 %tobool, label %if.then9, label %if.else

if.then9:                                         ; preds = %while.end
  %11 = load i8*, i8** %s, align 8
  %12 = load i32, i32* %len, align 4
  %add = add nsw i32 %12, 1
  %conv10 = sext i32 %add to i64
  %mul11 = mul i64 %conv10, 1
  %call12 = call i8* @realloc(i8* %11, i64 %mul11) #3
  store i8* %call12, i8** %s, align 8
  %13 = load i8*, i8** %s, align 8
  %14 = load i32, i32* %len, align 4
  %idxprom13 = sext i32 %14 to i64
  %arrayidx14 = getelementptr inbounds i8, i8* %13, i64 %idxprom13
  store i8 0, i8* %arrayidx14, align 1
  %15 = load i8*, i8** %s, align 8
  store i8* %15, i8** %retval, align 8
  br label %return

if.else:                                          ; preds = %while.end
  %16 = load i8*, i8** %s, align 8
  call void @free(i8* %16) #3
  store i8* null, i8** %s, align 8
  br label %if.end15

if.end15:                                         ; preds = %if.else
  %17 = load i8*, i8** %s, align 8
  store i8* %17, i8** %retval, align 8
  br label %return

return:                                           ; preds = %if.end15, %if.then9
  %18 = load i8*, i8** %retval, align 8
  ret i8* %18
}

; Function Attrs: nounwind
declare noalias i8* @malloc(i64) #1

declare i32 @__isoc99_scanf(i8*, ...) #2

; Function Attrs: nounwind
declare i8* @realloc(i8*, i64) #1

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
