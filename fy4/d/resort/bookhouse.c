
inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
�������û��������ֻ���飬�������ڵ��飬���������������ף����С���
��ֹϢ����ġ�������������϶�������ѩɽׯ���书���š���Щ�����Ƕ��鵶��
���ٺͶ��齣��ѩ���������Ѫ�Ľᾧ��
LONG
        );
        set("exits", ([ 
		  "west" : __DIR__"back_yard",
	]));

       set("objects", ([
                BOOKS"force_100":	1,
                BOOKS"skill/fall-steps_50":	1,
                BOOKS"skill/meihua-shou_40":	1,
                BOOKS"skill/shortsong_40":	1,
                BOOKS"skill/qidaoforce_50":	1,
                BOOKS"skill/diesword_50":	1,
                __DIR__"obj/shelf" : 1,

        ]) );
	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

