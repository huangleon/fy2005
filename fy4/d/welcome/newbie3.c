// Silencer@fy4 workgroup
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIY"����֮·"NOR);
	set("long", @LONG
��������������ͻȻһ����ԭ����һ��ʮ�ֲ�·����ǰ����·ƽ̹��������
��������·����᫣����վ����򾣼������������Ŀ���ϵ�ľ�Ʋ��ڸ��Ե�·�ڣ�
·��Զ��������ʲô�ڵȴ����㣿������ѡ����һ���أ�����ѡ������е����壬
����Ϊ[37m���������[32m�������ϣ��������ѡ��[1;32m���塢���塢�ɹ��塢����[0;32m������
��Ĳ������[37m����𡡣�������[32m�е�����ƪ��ѡ��7������
LONG
	);
	set("exits", ([
//  		"down" :  "/d/fy/fqkhotel",
		 "down" :  __DIR__"newbie4",
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",850);
	set("no_magic",1);
	set("no_fight",1);
	setup();
}


int init(){
	add_action("do_setrace", "setrace");
}


int valid_leave(object me, string dir) {

	if (dir == "down")
	if ( !me->query_temp("race_setup"))
		return notify_fail("���ڽ����������ǰѡ��һ�����塣
��ʽ�� setrace <�����������ֻ�ƴ����>\n");
	
	return ::valid_leave(me, dir);
}

int do_setrace(string arg)
{
	object me;
	
	me = this_player();
	
	if( !arg ) 
		return notify_fail("��ϣ��������һ�����壿
��ʽ�� setrace <�����������ֻ�ƴ����>\n");
		
	switch (arg) {
	case "����" :
	case "hanzu" :
			me->set("national","����");
			break;
        case "����" :
        case "manzu" :
                        me->set("national","����");
                        break;
        case "�ɹ���" :
        case "mengguzu" :
                        me->set("national","�ɹ���");
                        break;
        case "����" :
        case "miaozu" :
                        me->set("national","����");
                        break;
        default :
			return notify_fail("û���������
��ʽ�� setrace <�����������ֻ�ƴ����>\n");

	}
	write("�����Ͷ����"+ me->query("national") + "��\n");
	me->set_temp("race_setup", 1);
	return 1;
}

