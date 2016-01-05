inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "ɽ��");
        set("long", @LONG
Ⱥɽ����Զ���������ڽ������¼ŵ�ɽ�ȣ����˵ĵ��ϣ���¶���˼�����
��Ϣ��ɽ·������᫣���ʯ���м���Ұ����ǿ�����ͷ����һյ����ƳɵĿ����ƣ�
�����Ƕ��ɽʯ��ܷ紦�������׵Ŀ���������һ�㣬ϸ����ɽʯ�Ͼ���������
�֣��������죬��������ߡ�
LONG
);
        set("exits", ([ 
	"southdown" : __DIR__"road2",
	"westup" : __DIR__"road2a",
	]));
        set("objects", ([
        
	]) );
	set("outdoors", "eren");
    set("coor/x",0);
    set("coor/y",10);
    set("coor/z",50);
	set("map","eren");
	setup();
}


void init ()
{

   add_action("do_look", "look");
   add_action("do_northdown", "go");
}

int do_northdown(string arg)
{
   	object me, room;
   	me = this_player();

   	if (arg =="northdown") {
	   	if(me->query_temp("marks/eren/look")) {
	   		tell_object(me, "������С·����������ȥ��\n\n");
	   		message("vision", me->name(me)+"�������ѵ�ɽ·ת�˼�ת��ʧȥ����Ӱ��\n", environment(me),me );
	   		room = find_object(__DIR__"road3");
	   		if(!objectp(room)) room=load_object(__DIR__"road3");
	      	me->move(room);
	      	me->delete_temp("marks/eren/look");
	      	return 1;
	   	}
	}
   return 0;
}

int do_look(string arg)
{
   object me, room;
   me = this_player();
   
   if (arg!="rock" && arg!="ɽʯ" && arg!="stone" && arg!="��" )
   	return 0;

   tell_object(me,"�������£���ֻ��ͷ��ָ�����������ѵ�ɽ·���þ�Ŀ��������Ƴ�����·����ͨ
�����£�northdown����ɽ�ϱ���ɽ�ȡ�\n");
   message("vision",me->name(me)+"��ϸ�ؿ���ɽʯ�ϵ��֡�\n", environment(me),me);
   me->set_temp("marks/eren/look", 1);	
   return 1;
}

