inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�������ʮ�ɣ���һ�ٶ�ʮ�ɡ��������ѵ���ܦ��������ɽ���ϵĳǱ�������
����Ժ�����������١�¥���㲻��Ĵ����������������������ͣ��ͺ�������
�����������񻰡�
LONG
        );

        set("exits", ([ 
	"east" : __DIR__"octostreet",
	"west" : __DIR__"templeyard",
	]));
        set("objects", ([
                __DIR__"npc/hanren" : 1,
		__DIR__"npc/bhutanese" : 1,
                __DIR__"npc/mongol" : 1,   
        ]) );
        set("outdoors", "guanwai");
	set("coor/x",20);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}