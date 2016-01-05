

int main(object me, string arg1)
{
        int mark_loaded;
        int i,totalCount;
        int CountInEn=0;
        string dir,flag,arg;
        mixed *file;
        object *objectlist;
        
        if (!arg1)
        	return notify_fail("��Ҫ�쿴�ĸ��ļ���\n");
        	
        if (sscanf(arg1,"%s -%s",arg, flag)!=2)
        	return notify_fail("��ʽ����ȷ����쿴ʹ��˵����\n");
				        
        if (flag && flag != "destroy" && flag != "count")
        	return notify_fail("��������ȷ����ο�ʹ��˵����\n");
        	
        if (wiz_level(me)<5 && flag =="destroy")
        	return notify_fail("���Ȩ���޷��ݻ��ļ���\n");
        	        
        dir = resolve_path(me->query("cwd"), arg);

        if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += "/";
        file = get_dir(dir, -1);
        if( !sizeof(file) )
        {
                if (file_size(dir) == -2) 
                        return notify_fail("dir is empty��\n");
                else 
                        return notify_fail("no such dir or file��\n");
        }

        i = sizeof(file);
        
        write("object info for " + dir + "\n");
        
        if (sizeof(file))
        {
                int obCount;
                string obFileFullPath,obFile;
                for(i=0; i < sizeof(file); i++)
                {
                        obFileFullPath = dir + file[i][0];
                        
                        if(sscanf(obFileFullPath,"%s.c",obFile) == 1 || sscanf(obFileFullPath,"%s.o",obFile))
                        {
                                objectlist = children(obFile);
                                obCount = sizeof(objectlist);
                                if(obCount > 0)
                                {
                                        printf("object base name %s:  %d \n",obFile,obCount);
                                        totalCount += obCount;
                                }
                        }
                                
                        //find_object(dir + file[i][0])) 
                }
                printf("Total object count : %d \n",totalCount);
                
        		 
                for(i=0;i<sizeof(objectlist);i++)
                {
                	if (flag == "destroy")
                		destruct(objectlist[i]);
                	else if(environment(objectlist[i]))
                	{
                		CountInEn++;
//                		printf("obj No. %d is in %O\n",i,environment(objectlist[i]));
//                		reset_eval_cost();
                		
                	}
                	
        		}
        		if (flag == "destroy")
                	printf("ALL CHILDREN OBJECTS destroyed\n");
                else
                	printf("Total object count in Env: %d \n",CountInEn);
        }
        else 
                write("    no file��\n");
        write("\n");    
        return 1;       
}


int help(object me)
{
   write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	objectcount �ļ��� -����[0m
[0;1;37m����������������������������������������������������������������[0m   
   
�������鵱ǰ��Ϸ�е�ĳһָ����������

������
objectcount /obj/armor/cloth.c -count 
�������ͣգ��и��ļ��ĸ������

�������admin���ϣ���ʹ�� -destroy ����
objectcount /obj/armor/cloth.c -destroy 
���ݻ����и��ļ��ĸ���Ʒ�����ã���

[0;1;37m����������������������������������������������������������������[0m   
HELP
   );
   return 1;
}
