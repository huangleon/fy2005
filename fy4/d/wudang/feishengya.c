
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һ��ͻ��������ڣ�ɽ������һ��С·ֱ����ۣ�Ծ��������������
����Ȼ��Զ��
LONG
	);
	set("exits", ([
        "westup" : __DIR__"tianzhufeng",
	]));
	set("outdoors", "wudang");
	set("coor/x",20);
	set("coor/y",-70);
	set("coor/z",40);

       	set("objects", ([
        __DIR__"npc/yidianhong": 1,
        ]) );
	setup();

}
