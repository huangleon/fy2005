
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
  "west" : __DIR__"street3",
  "east" : __DIR__"midao1"
]));
        set("outdoors", "laowu");

	set("coor/x",40);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}

