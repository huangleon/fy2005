
inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
�䵱�������ɣ���ֲ�ͱڣ��������У��֦��չ������ͦ�Σ���ʫ�ƣ����Ʋ�
�������Σ��Կ���֦ɨ���������ð���������ͱ�֮�ϳ�������γ�һ����Ȼ��
�ϡ�֦Ҷ�ڰ�վ��ύ��������һ����ɡ���ַ���һ���������ֳ�����ͤ��
LONG
	);
	set("exits", ([
		"east" : __DIR__"jianquan",
		"northdown" : __DIR__"wall",
        "southup" : __DIR__"fourgate",
	]));
        set("objects", ([
                __DIR__"obj/tree" : 1,
       ]) );
	set("outdoors", "wudang");
	set("coor/x",10);
	set("coor/y",-40);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}
