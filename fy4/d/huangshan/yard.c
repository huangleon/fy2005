// mimicat@fy4
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "СԺ");
    	set("long", @LONG
��ש�̵ص�Ժ�䵱����һ�þ޴�������������޴�����ڸ����˴���ͥԺ��
û����֪�����ж��ϣ��ƺ��������ɹ��ֵ�ʱ��������ˣ����ɹ���������������
Ժ�������������ܿ����ż�����̳��������ֲ��һЩ���ݣ�����Ժ��ɾ����ࡣԺ
��������м���������������һ�����á�(����ץ����move�����80)        
LONG
        );
	set("exits", ([ 
    	"south" : __DIR__"antang",  
		"north" : __DIR__"songgu",
	]));
	set("item_desc",	([
		"pine":		"һ�ž޴��������û�е��Ṧ��������ȥ�ġ�\n",
		"����":		"һ�ž޴��������û�е��Ṧ��������ȥ�ġ�\n",
	]));	 
    	set("outdoors", "huangshan");
	set("coor/x",-140);
	set("coor/y",-35);
	set("coor/z",30);
	setup();
}

void init()
{
        add_action("do_climb", "climb");
        if( this_player() ) {
                tell_room(__DIR__"tree1", this_player()->name() + "���������˹�����\n");
        }
}
int do_climb(string arg)
{
	object me;
	
	me=this_player();
	if( arg!="tree" ) return 0;
	if( me->query_skill("move",1)< 80 + random(30))
	{
		message_vision(HIG"$N���ֱ��ŵ����Ŵ����������һʧ�־͵���������\n"NOR,me);
		me->start_busy(2);
		return 1;
	}
	else
        message_vision("$N�ֽŲ��ã����ݵ������˴�������\n",me);

        tell_room(__DIR__"tree1", this_player()->name() + "����������������\n");
        me->move(__DIR__"pinetree");

        return 1;
}
	
int valid_leave(object me, string dir)
{
        tell_room(__DIR__"tree1",
                "���µ�" + me->name() + "��" + to_chinese(dir) + "�뿪�ˡ�\n");
        return 1;
}

