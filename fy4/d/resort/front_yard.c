
inherit ROOM;

void create()
{
        set("short", "ɽׯǰԺ");
        set("long", @LONG
�����װ�ι��Ӷ����š�Ժ�ӵ�����ϡ������Ż�ɫ��ö�壬է���ƺ�û��ʲ
ô����ȴ���˸е�˵��������Ȼ��Ժ�ӵ�������ſξ����޼�����÷������ÿ��
�캮�ض�֮ʱ��ѩ�׶���͸�ŷۺ��÷������������
LONG
        );
        set("exits", ([ 
  		"south" : __DIR__"gate",
  		"north" : __DIR__"bamboo_hall",
]));
        set("outdoors", "resort");

	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

