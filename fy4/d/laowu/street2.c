
inherit ROOM;

void create()
{
        set("short", "���н�");
        set("long", @LONG
�ֵ������������и�ʽ�����ĵ��̣���������������������¥�Ƶ���Ц����
����������Щ�ˣ��ٿ�����һƬˮ���������磬�㼸���ֲ����⾿�����˼䣬����
���ϣ�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"street3",
  "west" : __DIR__"street1",
  "north" : __DIR__"inn",
   "south" : __DIR__"yingou",
]));
        set("outdoors", "laowu");

	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}

