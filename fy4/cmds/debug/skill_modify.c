// skill_modify.c by Silencer@fy4 workgroup

#define SKILL_FILE_NAME "daemon/skill_list.txt"
inherit F_CLEAN_UP;

int main(object me)
{
        int 	i, j, n, m, t,size, size_file, flag;
        string  file, first;
        string  arg_name, arg1, arg2, arg, line1, line2, tofile;
        string  *fileline, *extra;
	string  *format = ({ "file", "name", "type", "skill_class","effective_level","difficulty", 
        	"difficulty_r", "damage_level", "accuracy_level",
        	"practice_damage", "practice_force", "practice_limit", "bounce_ratio", "ic_effect",
        	"usage/animal-training",
		"usage/axe",
		"usage/blade",
		"usage/cursism",
		"usage/dagger",
		"usage/dodge",
		"usage/force",
		"usage/fork",
		"usage/hammer",
		"usage/herb",
		"usage/iron-cloth",
		"usage/literate",
		"usage/magic",
		"usage/move",
		"usage/parry",
		"usage/scratching",
		"usage/spear",
		"usage/spells",
		"usage/staff",
		"usage/stealing",
		"usage/sword",
		"usage/throwing",
		"usage/unarmed",
		"usage/whip",
		});
	
	mapping skill_data = ([]);        	
	string 	*line;
                      
        seteuid( geteuid(me) );
	
	line = explode(read_file(SKILL_FILE_NAME), "\n");
	write("���������ļ�/daemon/skill_list.txt������"+ (sizeof(line)-1) + "�����ܡ�\n");

//	write(line[2]+"\n");

	size = sizeof(format);
	
	for ( t=1; t<sizeof(line); t++){
		
		reset_eval_cost();
		
		// ����һ���书��ȫ������
		first = line[t];
		for (i= 0;i<(size-1);i++)
		{
			sscanf(first,"%s\t%s",arg1,arg2);
			if (format[i] == "name" || format[i] == "type"
				|| format[i] == "skill_class")
				skill_data[format[i]] = "\""+ arg1 + "\"";
			else
				skill_data[format[i]] = arg1;
			first = arg2;		
			if (i==size-2)	
				skill_data[format[i+1]] = arg2;
		}
		
		// ������书��Ӧ�ļ����ļ�
		file = "daemon/skill/"+ skill_data["file"] +".c";
		write(file + "\n");
		fileline = explode(read_file(file),"\n");
	
		tofile="daemon/skill/temp/"+ skill_data["file"] +".c";
	
		// �ο����ݿ�ʼ�����ļ�
		m = 0;
		extra= ({});
		
		for (i= 0; i<size; i++)
		{
			flag = 0;
			arg = skill_data[format[i]]; 
			if (arg=="0") continue;		// �����ݷ��أ�ע�ⲻҪ��SKILL�з�defaultΪ�㣩
						
			// ��һ���������ļ��е�ÿһ��
			size_file = sizeof (fileline);
			for (j=0;j<size_file;j++)
			{
				line2 = replace_string(fileline[j],"\t",""); 	//ȥTAB
				line2 = replace_string(line2, " ","");		//ȥ�ո�
				if (sscanf(line2, "set(\"%s\"%s",arg1, arg2) == 2){
	    				if (format[i] == arg1){ 	//�ҵ��Ļ��������ݸ���
	    					line2 = "\tset(\""+ format[i] + "\"," + arg+");";	    				
	    					fileline[j] = line2;
	    					flag = 1;
	    					break;
	    				}
	    			}  			
			}
			
			if (!flag) {	//û�ҵ��Ļ���¼����
				switch( format[i])
				{		//ȡ��һЩ����д�ڵ��������ļ����,����default�ģ�
					case "file":	continue;
					case "practice_damage":	if (arg == "30")	continue;
					case "practice_force":  if (arg == "5")		continue;
					case "ic_effect":	if (skill_data["usage/iron-cloth"]=="0") continue;
					case "practice_limit":  if (arg == "1") continue;
				}	
					
				line2 = "\tset(\""+ format[i] + "\"," + arg+");";    			
				extra += ({ line2 });
	    			m++;
	    		}
	    	}		
				

		
		flag = 0;    
		for (i=0;i<size_file;i++)
		{
			line2 = replace_string(fileline[i],"\t",""); 	//ȥTAB
			line2 = replace_string(line2, " ","");		//ȥ�ո�
			if (sscanf(line2, "set(\"%s\"%s",arg1, arg2) == 2){	// ȥ����ʱ��
				if (arg1 == "practice_bonus"
					||arg1 == "learn_bonus"
					|| arg1 == "black_white_ness"
				//	|| arg1 == "practice_limit"
					)
				continue;
			}			
			efun::write_file(tofile,fileline[i]+"\n",0);
			if (!flag && sizeof(extra)) {	//����extra��������set("name"��һ�к��档
				line1 = replace_string(fileline[i],"\t","");
				line1 = replace_string(line1, " ","");
				if (sscanf(line1,"set(\"name\"%s",arg_name) == 1)
				{	
					flag = 1;
					for (j=0;j<sizeof(extra);j++)
						efun::write_file(tofile,extra[j]+"\n",0);
				}	
			} 
		
		}
	}
	
	write ("ȫ���ļ�������ϡ�\n");
	return 1;
}


int help(object me)
{
  write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	skill_modify 
[0;1;37m����������������������������������������������������������������[0m   

	��ָ�/daemon/skill_list.txt�ļ��е����ݶ����
	����ÿһ�������ļ������޸ģ�����洢��/daemon/skill/temp/��
	Ҳ���ڴ�����������һЩ���������ٸ��ļ�ͬʱ���д���
	
	��ָ��Ϊ��ʦ�ܵ�����ʱʹ�ã���δ�����Ż���������֮��û���ϸ�
	�ļ�飬Ҳû��BUG������	�����ƻ����൱��
	
	tempĿ¼Ҳ����Ҫ�Լ�������
	
	�����Ҫʹ�ã�������ı������������������ϸ���tempĿ¼��
	���ļ��Ƿ������Ҫ��Ȼ���ٽ��串�ǵ�skillĿ¼�¡�

���ָ�skill_collect        	
			
[0;1;37m����������������������������������������������������������������[0m   
 
HELP
    );
    return 1;
}
 
