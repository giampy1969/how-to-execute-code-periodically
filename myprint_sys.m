classdef myprint_sys < matlab.System ...
        & coder.ExternalDependency ...
        & matlab.system.mixin.Propagates ...
        & matlab.system.mixin.CustomIcon

    % Displays (in simulation) or Prints (in execution) the input value
    % Takes 2 (useless) parameters from the mask
    
    % Copyright 2016 The MathWorks, Inc.
    
    properties (Nontunable) % block parameters
        Par1 = 11
        Par2 = 9600
    end
        
    methods
        % Constructor : this must be here
        function obj = myprint_sys(varargin) 
            coder.allowpcode('plain');
            % Support name-value pair arguments when constructing the object.
            setProperties(obj,nargin,varargin{:});
        end       
    end
    
    methods (Access=protected)
        
        function setupImpl(obj) % Implement setup
            
            if coder.target('Rtw') % Generated Code: call external init code
                coder.cinclude('myprint.h');
                coder.ceval('myprint_init', obj.Par1,obj.Par2);
            elseif coder.target('MATLAB') % Simulation: display values
                disp(['Init: Par1=' num2str(obj.Par1) ', Par2=' num2str(obj.Par2)]);
            end
            
        end
        
        function stepImpl(~,u) % Implement step (a.k.a. output)
            
            if coder.target('Rtw') %  Generated Code: call external output code
                coder.ceval('myprint_output', u);
                
            elseif coder.target('MATLAB') % Simulation: display values
                disp(['Step: Output=' num2str(u)]);
            end
            
        end
        
    end
    
    methods (Access=protected)
        %% Define input properties
        function num = getNumInputsImpl(~)
            num = 1;
        end
        
        function num = getNumOutputsImpl(~)
            num = 0;
        end

        function flag = isInputSizeLockedImpl(~,~)
            flag = true;
        end
        
        function varargout = isInputFixedSizeImpl(~,~)
            varargout{1} = true;
        end
        
        function flag = isInputComplexityLockedImpl(~,~)
            flag = true;
        end
        
        function varargout = isInputComplexImpl(~)
            varargout{1} = false;
        end
        
        function validateInputsImpl(~, u)
            if isempty(coder.target)
                % Run this always in Simulation
                validateattributes(u,{'uint8','uint16','uint32','uint64', ...
                    'int8','int16','int32','int64','single','double'}, ...
                    {'scalar','>=',0,'<=',255'},'','input');
            end
        end
        
        function icon = getIconImpl(~)
            % Define a string as the icon for the System block in Simulink.
            icon = 'myprint_sys';
        end
    end
    
    methods (Static, Access=protected)
        function simMode = getSimulateUsingImpl(~)
            simMode = 'Interpreted execution';
        end
        
        function isVisible = showSimulateUsingImpl
            isVisible = false;
        end
    end

    methods (Static)
        function name = getDescriptiveName()
            name = 'Analog Output and Serial Transmit';
        end
        
        function b = isSupportedContext(context)
            b = context.isCodeGenTarget('rtw');
        end
        
        function updateBuildInfo(buildInfo, context)
            if context.isCodeGenTarget('rtw')
                % Update buildInfo
                rootDir = fullfile(fileparts(mfilename('fullpath')),'.');
                buildInfo.addIncludePaths(rootDir);
                buildInfo.addIncludeFiles('myprint.h');
                buildInfo.addSourceFiles('myprint.cpp',rootDir);
            end
        end
    end
end
