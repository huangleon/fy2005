inherit ROOM;
void create()
{
    set("short", "���ڽ�");
    set("long", @LONG
����ʯ���Ѿ����ȵø߸ߵ͵ͣ����ٺ��������ѧ�Ӵ�����̤�����ǵ�����֮
·������ĩ��ǽͷ����ͷ�ܶ��ķŰ񴦣���Цŭ�����ߣ��⾲���Ļʰ��ľ�
�˶����˼䱯ϲ��������Ƕ����˵�ʥ�ع�Ժ�������Ǿ�����֣�����������ʫ�硣
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"nwind1",
	"north" : __DIR__"examp",
	"west" : __DIR__"jssju",
	"south" : __DIR__"shishe",
      ]));
    set("objects", ([
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",-20);
    set("coor/y",80);
    set("coor/z",0);
    set("map","fynorth");
    setup();

}
