
inherit ROOM;

void create()
{
        set("short", "�����޹�С�Ƽ�");
        set("long", @LONG
С�ƼҼ����Ӳ����ȣ����̿���������ϰ��ﳤ�úܲ�������֪Ϊʲô��
����������壬������һ�����ˡ�һ�顰̫���ŷ硱��ľ�����ƹ�������ں�����
ҡҷ��
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"street1",
]));

        set("objects", ([
        __DIR__"npc/dang" : 1,
                        ]) );
	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}

