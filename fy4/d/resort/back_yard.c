
inherit ROOM;

void create()
{
        set("short", "ɽׯ��Ժ");
        set("long", @LONG
ׯ���СϪ�������γ�һ��СС���ٲ����ٲ�����һС̶ˮ������ľ�ɫ����
ʤ�ա����ߵ�С���в��źܶ�����ɫɫ���书���ţ�����ѩׯ��һ���Ļ������
����һ��СС�������ҡ�
LONG
        );
        set("exits", ([ 
  		"south" : __DIR__"bamboo_hall",
  		"northdown" : __DIR__"meiyutan",
  		"east" : __DIR__"bookhouse",
  		"west" : __DIR__"exerhouse",
	]));
        set("objects", ([
                __DIR__"npc/w_guy" : 1,
                __DIR__"npc/b_guy" : 1,
        ]) );
        set("outdoors", "resort");

	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
	object ob;
        if( dir == "east" && ob=present("oldguy", this_object()))
        {
		return notify_fail("��������·��"+ob->name()+"��ס�� ��\n");
	}
		return 1;
}
