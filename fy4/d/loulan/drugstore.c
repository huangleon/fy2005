inherit ROOM;

void create()
{
        set("short", "�ٲ�ի");
        set("long", @LONG
�ٲ�ի�����˽в���ֱ���ݴ������ǹ��ܵĹϹ����ӣ������й���ǧ�꣬����
�����ṦҲ�����һ�����֡������Ľ�ɫ����Ȼ�����ڿ������¥�����￪��һ
������ͨͨ��ҩ�ݵ꣬���˲��ò���̾����ص����ƲƸ����Ѿ����Ƿ��˿�������
���ˡ�
LONG
        );

        set("exits", ([ 
		"south" : __DIR__"weststrt2",
	]));
        set("objects", ([
                __DIR__"npc/bu" : 1,
	]) );
        set("indoors", "loulan");

	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}
