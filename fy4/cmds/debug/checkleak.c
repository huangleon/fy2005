#include <combat.h>
#include <ansi.h>
#define SYNTAX	"ָ���ʽ��checkleak <dir>\n"
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	int i;
	string direc,*dir, roomname;
	string status;
	object room;
        if(!me->query("env/yesiknow")) return notify_fail("���ָ���Ѿ����ϳ��ˣ�\n");
	status = wizhood(me);
	if( me!=this_player(1)
	|| wiz_level(me) < wiz_level(status) )
		return notify_fail("��û��Ȩ��ʹ�����ָ�\n");
	if( !arg ) return notify_fail(SYNTAX);
	if( sscanf(arg, "%s", direc)!=1 )
		return notify_fail(SYNTAX);
	seteuid(getuid());
	dir = get_dir(arg+"/");
        for(i=0; i<sizeof(dir); i++) {
	if( sscanf(dir[i],"%s.c", roomname) != 1) continue;
	if( room = find_object(arg+"/"+roomname+".c"))
			destruct(room);	
	room = load_object(arg+"/"+roomname+".c");
	if(!room->query("coor"))
	log_file("LEAK",sprintf("%s/%s\n",arg,roomname));
	}
	return 1;
}

int help(object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	checkleak <Ŀ��Ŀ¼>[0m
[0;1;37m����������������������������������������������������������������[0m   

    ��; : ���һ��һ��Ŀ¼�µķ����Ƿ��ܱ���ͨ����

[0;1;37m����������������������������������������������������������������[0m   
HELP
        );
        return 1;
}
