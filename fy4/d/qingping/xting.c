//XXDER
inherit ROOM; 
void create()
{
   set("short", "С��");
   set("long", @LONG
����һ��С�ɶ����µ�¥����¥�²��õ����С�������鷿�����м���һ��С
��ľ���������Ա߰����İ����ӣ�������һ����������������˱�ī��̨��������
�Ϸ��˼����顣�����Ա���һ��ܣ����ϰ����˸�ʽ�������顣վ������ǰ����
��ȥ�����Կ�������İŽ��ͳ�����һ�ǡ�
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
      "north" : __DIR__"garden",
      "up" : __DIR__"bedroom3",
   ]));

   set("objects", ([
      __DIR__"npc/laner": 1,
      __DIR__"obj/desk": 1,
   ]) );

   set("item_desc", ([
      "window": "������ȥ��ֻ��С����ˮ����Ҷ�컨���㱻�������ľ�ɫ���������ˡ�\n",
      "����": "������ȥ��ֻ��С����ˮ����Ҷ�컨���㱻�������ľ�ɫ���������ˡ�\n",
   ]) );
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
	
}

void init()
{
   add_action("do_look", "look");
}

int do_look(string arg)
{
   object me;

   me = this_player();
   if(!arg || (arg != "bajiao" && arg != "�Ž�")) 
   return 0;
   me->set_temp("marks/bajiao",1);
   tell_object(me, "����İŽ����������֣���ע�⵽�Ž��µ����ƺ����ɹ���\n");
   return 1;
   
}
