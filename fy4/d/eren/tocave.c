// Silencer@FY workgroup  ���˿�
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "����");
        set("long", @LONG
����ҵ����ֿ�ץ��ϤϤ����������ʯ����������µ�����Ȼ�������˼�����
����һ���Ķ������ǳ��ڶ����ϵ�ǧ����٣��������˵����������ˮ��ץ���˾�
���ĵ��ݣ���������ס����׹����ͷ��ͷ������Щ�չ⣬Ҳ��ץ�Ź��ٻ���ϣ����
�ϵ��棬�����Ǻ�������������ȥ��Ҳû�л�ͷ��·�ˣ����ѡ����ʲô�أ�
LONG
        );
	set("exits", ([ 
//	    	"northdown" : __DIR__"yongdao1",  
	]));
    	set("objects", ([

    	]) );
  	set("indoors", "eren2");
	set("coor/x",0);
    	set("coor/y",0);
	set("coor/z",0);
	set("valid_startroom",1);
	setup();
}

void init()
{
	add_action("do_climb","climb");
	add_action("do_dive","jump");
	add_action("do_dive","jumpdown");
}

int do_dive(string arg)
{
        object room;
        object me;
        me = this_player();
        call_out("jump_down",6,me);
        me->start_busy(3);
	tell_object(me,"�㾲���������룬Ҳ������ҹҹ�ķܶ�������Ϊ��������һ�̣�����Ϊ����һԾ��\n");
	message_vision(YEL"$N�������˿�������Ȼ�ɿ��˹��٣�����Ծȥ��\n"NOR,me);
	tell_object(me,YEL"��Խ׹Խ�죮���������������ߺ����ӹ���\n"NOR);
        return 1;
}

int jump_down(object me)	{
        object room;
        if(!objectp(me)|| me->is_ghost() || environment(me)!=this_object()) return 1;
	room=find_object(AREA_EREN2"cavein");
	if(!objectp(room)) 
        	room = load_object(AREA_EREN2"cavein"); 
	me->move(room);
	tell_object(me,HIW"��ã�������ͨ��һ���ȵ���ʵ�أ���Χ��Ȼһ�������������յ����������ۡ�\n"NOR);
        return 1;
}


int do_climb(string arg)
{
        object room;
        object me;
        me = this_player();
	if (arg=="up" || !arg || arg=="����" || arg=="vine"){
	        call_out("climb_out",6,me);
	        me->start_busy(3);
		tell_object(me,"���շ��������������Щ׼��������Щ����������\n");
		message_vision(YEL"$Nץס������������������ȥ��\n"NOR,me);
		return 1;
	}
	return notify_fail("��Ҫ��ʲô��\n");
}

int climb_out(object me)	{
        object room;
        if(!objectp(me)|| me->is_ghost() || environment(me)!=this_object()) return 1;
	room=find_object(__DIR__"vroad5");
	if(!objectp(room)) 
        	room = load_object(__DIR__"vroad5"); 
	me->move(room);
	tell_object(me,HIW"��ã������������˶��ڡ�\n"NOR);
        return 1;
}
