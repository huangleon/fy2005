
inherit ROOM;
void create()
{
    set("short", "������");
    set("long", @LONG
��·������ɾ������������Ƿ����˼䣬��ϡ�Ǵ�˵��������Ӱ��ߣ�һ
��ѩ�׵�ʯͷ������һ�꾧Ө��͸��ҡҷ���˵�С�ݣ�ʯ�Ͽ������֣���������ʯ��
LONG
	);
    
    set("exits", ([ /* sizeof() == 4 */
        "west" : __DIR__"anbian1",
        ]));
    set("objects", ([
        __DIR__"obj/boat" :1,
        ]));
    set("outdoors", "bat");
	set("coor/x",10);
	set("coor/y",-20);
	set("coor/z",30);
    setup();
    replace_program(ROOM);
}



