inherit ROOM;
void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
̩ɽ������һ������խ����ʯ·��·�ľ�ͷ���Ǻպ�������[33m����ƽɽׯ��[32m��
·�����˲��࣬�����Ķ�������ֺ��ܣ���Ϊ��ƽ���Ͱ�����������ԭ���ֵĵ�һ
���֣�һ����ƽ���������޵����£�Ľ�����������ࡣ
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : AREA_QINGPING"gate",
  "southwest" : __DIR__"road2",
  "north" : __DIR__"road3",
]));

   	set("outdoors","jinan");
	set("coor/x",70);
	set("coor/y",130);
	set("coor/z",0);
	setup();
	
	replace_program(ROOM);
}
