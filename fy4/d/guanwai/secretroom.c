inherit ROOM;

void create()
{
	set("short", "�ܿ�");

	set("long", @LONG
һ��խС�������ܿߣ�һ˿����͸���촰���˽��������пյ���ûʲô���裬
һ��һ��һ�ˡ������������Ÿ���������������Ҿơ������£�����һ���ܰ�С��
�ˣ���Ҳ�����������ż����İ�ɫ���ӣ����Ŷ��ܴ�����ҡ�
LONG);

	set("type","street");
        set("exits", ([ 
		"east" : __DIR__"wallhole",
        ]));
        set("objects", ([
                __DIR__"npc/ying" : 1,
	]) );
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
        setup();
	replace_program(ROOM);
}