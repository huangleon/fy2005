#include <room.h>  
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short",MAG "����"NOR);
  set("long",@LONG
��ɫ�Ǵ������˵���ɫ�������������Ӷ������϶й������ġ��������˸���һ
λ���������������Ů��˫�������������ڰ���������л������¶��������صĹ�
��
LONG
  );
  	set("exits/center" ,__DIR__"shishi");
        set("objects", ([
                __DIR__"npc/maggirl" : 1,
       ]) );
  
	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
 }
 void init()
{
	add_action("do_love","tell");
}
void reset()
{
    ::reset();
 	delete_temp("mark/gived");
}  
int do_love(string arg)
{
	string  obname, things;
	object me;
	object ob;
	object hook;
	me=this_player();
        if(!arg || sscanf(arg, "%s %s", obname, things)!=2 )
                return notify_fail("tell <��> <��>\n");

	if (!(ob=present("mag girl",this_object()))) return 0;   
	if (!arg) return 1;
	if (query_temp("mark/gived")) return 1;
	if(obname == "girl") {
                if(things[0..13] == "���ϵر�˫�ɿ�") {
                        message_vision(MAG "\n$N��$n̾����̫�����ˣ����黷Ӧ������ˣ�������㡣\n", ob, this_player());
                        set_temp("mark/gived",1);
                        hook = new(__DIR__"obj/lovering.c");
                        hook->move(me);
                        return 1;
                }
        }
        return 0;
}