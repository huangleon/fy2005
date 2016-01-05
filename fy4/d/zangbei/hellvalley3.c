inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "������");
        set("long", @LONG
����һ������ɭ��ɽ�ȣ���ʹ���������ҵ����磬ɽ������Ȼ������������ɽ
�Ⱥܶ������걻���������ţ���֪��ǳ����ȻҲ����������Խ��ȥ�ˡ�����������
һ��ù�õ���ζ�����������ţ���Ȼӳ����߲ʵĹ�ԡ��������ν������������
���ģ�ż����·���Է�����������С���Խ���ϣ�һ��С��մ��һ�����������̾�
һͷ������ȥ������һƬ����֮�ȡ�
LONG
        );
        set("exits", ([ 
		"southwest":  __DIR__"hellvalley2",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1970);
        set("coor/y",630);
        set("coor/z",10);
	set("map","zbwest");
	setup();

}


void init()
{
        add_action("do_dive", "jump");
        add_action("do_dive", "jumpdown");
        add_action("do_dive", "jumpto");
        add_action("do_climb", "climb");
}

int do_dive(string arg)
{
        object room;
        object me;
        me = this_player();
        call_out("jump_down",6,me);
        me->start_busy(3);
	message_vision(YEL"$N�������˿�����һ���ۣ���ɽ������ȥ��\n"NOR,me);
	tell_object(me,YEL"��Խ׹Խ�죮���������ƺ�������һ���ҽУ�����ë���Ȼ��\n"NOR);
        return 1;
}

int jump_down(object me)	{
        object room;
        if(!objectp(me)) return 1;
  	if (me->is_ghost()) return 1;
	room=find_object(__DIR__"hellvalley4");
	if(!objectp(room)) 
        	room = load_object(__DIR__"hellvalley4"); 
	tell_object(me,WHT"ֻ������ͨ��һ�������䵽�˼�ʵ���������ϣ�ԭ�����ɽ��һ�㶼���\n"NOR);
	me->move(room);
	message("vision","ֻ������ͨ��һ����"+me->name()+"���������������\n"NOR,environment(me),me);
        return 1;
}


int do_climb(string arg)
{
        object obj;
        object me, room;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( arg == "ɽ" || arg == "mountain" || arg == "down")
        {
		write("����ط�̫�գ����������ȥ��\n");
        	return 1;
        }
        else
        {
                write("�㲻������ô����");
                return 1;
        }
}