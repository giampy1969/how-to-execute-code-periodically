function algorithm()
% Example of IIR filter fed by a square wave, with output display or print
% Copyright 2017, The MathWorks, Inc

%% initialization: effective only the first time the function is called

persistent x c out
if isempty(x) || isempty(c) || isempty(out)
    x=0;c=-1;out=myprint_sys;
end

%% step: this part updates the input c, the state x, and finally prints x

% Counter, limited to 40
c=c+1; if c>40; c=0; end

% filter: next state
x=(c<=20)*20 + 0.8*x;

% out(x) calls out.step(x), which prints the value of x when called
% from either MATLAB (in interpreted mode) or the OS (as an executable)
out(x);