
inherit ROOM;

void create()
{
        set("short", "���ر���");
        set("long", @LONG
�����µı��ӣ��������Ի�׳�ۡ�����ʮ�ɣ����������������Ӱ��ܽ�����
����ɫȴ����ȱ𴦻�Ҫ�Щ��һ�ο���¶�ں����ϣ�����ǿ�ʼ�⽭��ʱ��
�����ġ���֦Ҳ��֪��˭��ƽ�ˣ�����ȴ����һС��¶�ں����⡣
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"street3",
]));
        set("outdoors", "laowu");

	set("coor/x",31);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}

