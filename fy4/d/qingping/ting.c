inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���ܴ󣬲��õļ������ɣ�����������һ�����磬�����ϻ�����һƬ��������
��ɽ�壬ʮ���ն񣬿���ȥ��Щ��ɽ�����ֱȻ�ɽ����Щ�������������ӵ�����
������Ҳ��֪����������δ�������ǰ��һ�Ѹߴ����̴ľ�Σ������������޲���
�Ŀ��棬����ǽ�Ϲ����������黭��������Щ��������û�б�İ��衣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wuchang1",
  "east" : __DIR__"aroad",
  "north" : __DIR__"northting",
  "south" : __DIR__"southting",
]));

   set("objects", ([
      __DIR__"npc/gongsun": 1,
   ]) );
	set("coor/x",-50);
	set("coor/y",0);
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

   if (!arg || (arg != "����" && arg != "pingfeng")) return 0;
   tell_object(me, "ֻ����Ⱥɽ֮�䣬��������֮���ƺ��и���ɫ�ĺ������ں��Ķ�����
�ƺ���һ������ӡ�ۣ�����ϸ�Ǿ��Է��ֲ��˵ġ� \n");
   me->set_temp("marks/foundgate", 1);
   return 1;
}
