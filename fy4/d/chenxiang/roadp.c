
inherit ROOM;

void create()
{
        set("short", "��Ұ");
        set("long", @LONG
����һ���ޱߵ�ɳ���أ�ɽ�Ƶ�������ͻȻ������Ӱ���١������������
�綼��ů�ġ����ϵ�ʯ������һ�ְ������ɫ�������Ǳ���ѪȾ���һ��������ǰ
�߾����ޱ��޼ʵĴ�ɳĮ��һ�������˾���Ҳû�л�ͷ��·�ˡ�
LONG
        );
        set("exits", ([ 
  "northwest" : AREA_QUICKSAND"desert2",
  "south" : __DIR__"road",
]));
        set("outdoors", "chenxiang");

	set("coor/x",-10);
	set("coor/y",80);
	set("coor/z",-10);
	setup();
}

