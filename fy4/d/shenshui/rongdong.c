// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�ܶ�");
        set("long", @LONG
�㷢���Լ�����һ�����ܶ��ڣ��м���һ����ˮ�أ�ˮ����ˮ���壬ȴ������
�ף�����������Ƕ�Ŵ��СС������͸�����ɫ�ı��ǣ�ӳ��ˮ��������͵Ĺ�ʡ�
������ǧ�˰�̬������ɫ������ʯ��ʯ����Ƕ���˴��СС�����飬�˾�������ֻ
Ӧ�����С�
LONG
        );
   set("exits", ([ 
      "north": __DIR__"rongdong1",
   ]));
	set("coor/x",10);
	set("coor/y",-40);
	set("coor/z",20);
	setup();
}

void init()
{
   add_action("do_dive", "dive");
}

int do_dive()
{
   object me, room;
   me = this_player();

  message_vision("$N�ߵ��رߣ�����һ�����������˳����\n\n", me);
  room = find_object(__DIR__"gongnei");
  if(!objectp(room))  room = load_object(__DIR__"gongnei");
  me->move(room);
  message("vision", me->name()+"��ͨһ������������������\n", environment(me), me);
  return 1;
}


