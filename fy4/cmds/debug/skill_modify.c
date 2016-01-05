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
	write("¶ÁÈëÊý¾ÝÎÄ¼þ/daemon/skill_list.txt£¬¹²¼Æ"+ (sizeof(line)-1) + "¸ö¼¼ÄÜ¡£\n");

//	write(line[2]+"\n");

	size = sizeof(format);
	
	for ( t=1; t<sizeof(line); t++){
		
		reset_eval_cost();
		
		// ¶ÁÈëÒ»ÐÐÎä¹¦µÄÈ«²¿²ÎÊý
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
		
		// ¶ÁÈë´ËÎä¹¦¶ÔÓ¦µÄ¼¼ÄÜÎÄ¼þ
		file = "daemon/skill/"+ skill_data["file"] +".c";
		write(file + "\n");
		fileline = explode(read_file(file),"\n");
	
		tofile="daemon/skill/temp/"+ skill_data["file"] +".c";
	
		// ²Î¿´Êý¾Ý¿ªÊ¼ÐÞÕýÎÄ¼þ
		m = 0;
		extra= ({});
		
		for (i= 0; i<size; i++)
		{
			flag = 0;
			arg = skill_data[format[i]]; 
			if (arg=="0") continue;		// ¿ÕÊý¾Ý·µ»Ø£¨×¢Òâ²»ÒªÈÃSKILLÖÐ·ÇdefaultÎªÁã£©
						
			// ÖðÒ»ËÑË÷¼¼ÄÜÎÄ¼þÖÐµÄÃ¿Ò»ÐÐ
			size_file = sizeof (fileline);
			for (j=0;j<size_file;j++)
			{
				line2 = replace_string(fileline[j],"\t",""); 	//È¥TAB
				line2 = replace_string(line2, " ","");		//È¥¿Õ¸ñ
				if (sscanf(line2, "set(\"%s\"%s",arg1, arg2) == 2){
	    				if (format[i] == arg1){ 	//ÕÒµ½µÄ»°ÓÃÐÂÊý¾Ý¸²¸Ç
	    					line2 = "\tset(\""+ format[i] + "\"," + arg+");";	    				
	    					fileline[j] = line2;
	    					flag = 1;
	    					break;
	    				}
	    			}  			
			}
			
			if (!flag) {	//Ã»ÕÒµ½µÄ»°¼ÍÂ¼ÏÂÀ´
				switch( format[i])
				{		//È¡³öÒ»Ð©²»±ØÐ´ÔÚµ¥¸ö¼¼ÄÜÎÄ¼þÀïµÄ,»òÕßdefaultµÄ£¬
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
			line2 = replace_string(fileline[i],"\t",""); 	//È¥TAB
			line2 = replace_string(line2, " ","");		//È¥¿Õ¸ñ
			if (sscanf(line2, "set(\"%s\"%s",arg1, arg2) == 2){	// È¥³ý¹ýÊ±µÄ
				if (arg1 == "practice_bonus"
					||arg1 == "learn_bonus"
					|| arg1 == "black_white_ness"
				//	|| arg1 == "practice_limit"
					)
				continue;
			}			
			efun::write_file(tofile,fileline[i]+"\n",0);
			if (!flag && sizeof(extra)) {	//¼ÓÈëextraµÄÊý¾ÝÔÚset("name"ÄÇÒ»ÐÐºóÃæ¡£
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
	
	write ("È«²¿ÎÄ¼þ´¦ÀíÍê±Ï¡£\n");
	return 1;
}


int help(object me)
{
  write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÎ×Ê¦Ö¸Áî¸ñÊ½ : 	skill_modify 
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

	´ËÖ¸Áî½«/daemon/skill_list.txtÎÄ¼þÖÐµÄÊý¾Ý¶ÁÈëºó
	¶ÔÕÕÃ¿Ò»¸ö¾ßÌåÎÄ¼þ½øÐÐÐÞ¸Ä£¬¶øºó´æ´¢ÔÚ/daemon/skill/temp/ÏÂ
	Ò²¿ÉÔÚ´ËÃüÁîÖÐÔö¼ÓÒ»Ð©²ÎÁ¿¶ÔÊý°Ù¸öÎÄ¼þÍ¬Ê±½øÐÐ´¦Àí¡£
	
	´ËÖ¸ÁîÎªÎ×Ê¦×Üµ÷¼¼ÄÜÊ±Ê¹ÓÃ£¬²¢Î´½øÐÐÓÅ»¯£¬£¨»»ÑÔÖ®£¬Ã»ÓÐÑÏ¸ñ
	µÄ¼ì²é£¬Ò²Ã»ÓÐBUG±£»¤£©	ËùÒÔÆÆ»µÐÔÏàµ±´ó¡£
	
	tempÄ¿Â¼Ò²ÐíÐèÒª×Ô¼º½¨Á¢¡£
	
	Èç¹ûÐèÒªÊ¹ÓÃ£¬×î»ù±¾µÄ±£»¤»úÖÆÊÇÔËÐÐÍêºó£¬×ÐÏ¸¼ì²étempÄ¿Â¼ÏÂ
	µÄÎÄ¼þÊÇ·ñ·ûºÏÐèÒª£¬È»ºóÔÙ½«Æä¸²¸Çµ½skillÄ¿Â¼ÏÂ¡£

Ïà¹ØÖ¸Áî£ºskill_collect        	
			
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
 
HELP
    );
    return 1;
}
 
