inherit ROOM;
void create()
{
        set("short", "�䳡");
        set("long", @LONG
������ƽɽׯ���䳡��ƽ������һƬ����֮������ƽ���£�������ϰ��������
ƽ���Ͱ����նԵ��ӹ̼ܽ�Ϊ�ϸ�Ҳ����Ϊ��ˣ����µ����书�󶼲���������
Ʒ�ж���������֮��Ī����������ʱ�䳡֮��ȴ����һ�ˣ�����д��·�����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wuchang2",
  "south" : __DIR__"wuchang3",
  "west" : __DIR__"gate",
  "east" : __DIR__"ting",
]));

   	set("outdoors","qingping");
	set("coor/x",-60);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	
}

int valid_leave(object me, string dir)
{
   tell_room(__DIR__"treetop", "�䳡�ϣ�"+me->name()+"��"+to_chinese(dir)+"��ȥ��\n" );
   return 1;
}

