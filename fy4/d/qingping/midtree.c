// XXDER@fy
inherit ROOM;
#include <command.h>
#include <ansi.h>
void create()
{
        set("short", "������");
        set("long", @LONG
�������Ѿ��������ϻ����ϣ�����������Ҳ͸����ï�ܵ�[33m����[32m����ǰ�������
����ؿ����˴���Ӿ�ס��Ժ�䣬�������������԰���г�������������۵ף�
������һ���������Ĳ���û��С·��֪ͨ��η���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
   "down" : __DIR__"garden",
   ]));

   set("item_desc", ([
   		"treetop" : "����ï�ܵÿ�������գ������ƺ���һ��ں����Ķ���������Ҫ���������ſ��������\n",
		"����" : "����ï�ܵÿ�������գ������ƺ���һ��ں����Ķ���������Ҫ���������ſ����������\n",
   ]) );
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",10);
        setup();
}

void init()
{
   add_action("do_climb", "climb");
}

int do_climb(string arg)
{
   object me, room;
   int mlvl;
    me = this_player();
   if(!arg || (arg != "�ϻ���" && arg != "tree" && arg!= "up")) return 0; 
   
   mlvl = (int)me->query_skill("move");
   if(mlvl < 70)
      message_vision("$Ņͷ���������������ﲻ�ɵ���Щ���š�\n", me);
   else{
      message_vision("$N����������������ȥ��\n", me);
      room = find_object(__DIR__"treetop");
      if(!objectp(room)) room=load_object(__DIR__"treetop");
      me->move(room);
   }
   return 1;
}
