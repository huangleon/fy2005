// Room: girl


inherit ROOM;
#include <room.h>

void create()
{
        set("short", "����");
        set("long", @LONG
���ڶ����˸�����������ʱ�ʵ�ˮ������������ɼ���������鱦��������
�����������ϣ��ƺ�б����һ������Ů�ӡ�
LONG
        );
        set("objects", ([
                __DIR__"npc/shui": 1,
        ]) );
       

	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",10);
	setup();
//	replace_program(ROOM);      
}

void init(){
	add_action("do_open", "push");
}



int do_open(string arg)
{
	object room;
        object me;  
	me=this_player();
	if(!objectp(room = find_object(__DIR__"goldroom")))
	room = load_object(__DIR__"goldroom");
	switch (arg)
         {
         case "jade":
         case "���":
             if(query("exits/west")) return notify_fail("���Ѿ��ǿ����ˡ�");
             message_vision("$N�����������һ��������ϳ���һ��С�š�\n",this_player());
             set("exits/west",__DIR__"goldroom");
		room->set("exits/east",__DIR__"girlroom");
	     call_out("closepath",5,room);
             return 1;
         }
}

void closepath(object room)
{
tell_object(this_object(),"С�ţ�֨����һ���ֹ����ˡ�\n");
delete("exits/west");
room->delete("exits/east");
}