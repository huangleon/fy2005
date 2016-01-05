// updatepartner.c
// ��������һ��Ŀ¼������Ŀ¼�µ�.c�ļ�
// ---- Silencer@FY4 workgroup

#include <ansi.h>
inherit F_CLEAN_UP;
int total, error;
int update_files(object me, string *files, string parent, int count);

int main(object me, string arg)

{
    	string arg1;
    	string *files;
    	int count;
    	total = 0;
    	error = 0;
    	    	
    	set_eval_limit(1); 
    	seteuid(getuid());
    	if(!arg || arg=="") return notify_fail("��ʽ���ԣ�\n");
		if (me->query("id")!= "silencer")
			return notify_fail("˽�˵����������localʹ�á�\n");
		
		files =get_dir(arg);
    	update_files(me, files, arg, 3);
    	
    	write(HIR"\n\n�����սᣬ��쿴������Ϣ��\n"NOR);
    	write(HIR" �ɹ� : "+ total + ";   ʧ��" +error + "\n"NOR);
    	return 1;
}


int update_single_file(object me, string file)
{
        int i;
        object obj, *inv;
        string err;

        seteuid( geteuid(me) );

        if (!file) file = me->query("cwf");
        if (!file)
                return notify_fail("��Ҫ���±���ʲ�ᵵ����\n");

        if( (obj = present(file, environment(me))) && interactive(obj) ) {
        	write("���������롣\n");
                return 1;
	}
	
        if( file == "me" ) {
        	write("���������롣\n");
                return 1;
	}
	else {
                file = resolve_path(me->query("cwd"), file);
                if( !sscanf(file, "%*s.c") ) file += ".c"; 
        }

        if( file_size(file)==-1 )
                return notify_fail("û�����������\n");

        me->set("cwf", file);

        if (obj = find_object(file)) {
                if( obj==environment(me) ) {
                        if( file_name(obj)==VOID_OB )
                                return notify_fail("�㲻���� VOID_OB �����±��� VOID_OB��\n");
                }

                inv = all_inventory(obj);
                i = sizeof(inv);
                while(i--) {
                        if(userp(inv[i])) {
                        	inv[i]->move(VOID_OB, 1);
                        } else {
                        	destruct(inv[i]);
			}
                }

                destruct(obj);
        }

        if (obj) return notify_fail("�޷�����ɳ�ʽ�롣\n");

    	write("���±��� " + file + "��");
        err = catch( call_other(file, "???") );
        if (err) {
                printf("��������\n%s\n", err );
        	error++;
        }	
        else {
                total++;
                write("����ɹ���\n");
   		log_file( "UPDATE_LOG", sprintf("(%s)%s updated %s\n", ctime(time()), me->query("name"), file));
               	if( (i=sizeof(inv)) && (obj = find_object(file))) {
        		while(i--)
                        	if( inv[i] && userp(inv[i]) ) 
					inv[i]->move(obj, 1);
                }
        }
                
        return 1;

}



int update_files(object me, string *files, string parent, int count){
	
	int i, size;
	string *files2;
	
	reset_eval_cost();
	for(i=0; i<sizeof(files); i++) {
		if (parent + files[i] == "/cmds/adm/updatepartner3.c") continue;
		size=sizeof(files[i]);
		if(files[i][(size-2)..size]==".c") {
	  	       	update_single_file(me, parent+files[i]);
//	  	       	me->ccommand(sprintf("update %s%s",parent,files[i]));
	        } else if (arrayp(get_dir(files[i]))) {
			if (count>1) {
				files2 = get_dir(parent+files[i]+"/");
				update_files(me, files2, parent+files[i]+"/",count-1);	
			}
		}
	}
	return 1;
}


int help(object me)
{
  	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	updatepartner <Ŀ¼��>	[0m
[0;1;37m����������������������������������������������������������������[0m   

������	updatepartner /d/fy/ 
������� /d/fy/, /d/fy/npc/, /d/fy/npc/obj/ �� /d/fy/obj/Ŀ¼
 
��������һ��Ŀ¼������Ŀ¼�µ�.c�ļ�

[0;1;37m����������������������������������������������������������������[0m 
HELP
    );
    return 1;
}
 
