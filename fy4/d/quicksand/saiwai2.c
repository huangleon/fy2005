
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���Ƶ����Ȼ���ʣ����������һ���޼ʵ�ɳĮ������ں����������ɳ�ڷ�
�裬��ɳ������ɳ������������ϣ������ǲ��ŭͶ�µı�����ڤڤ�з·�������
а����������κ�����ʱ���п���ͻȻ��Ұ��������ɳ���ϡ�·����ָ�ţ�
    [33m  ����ɳĮ�����������豸��ˮԴ����Ӷ��С�[32m
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"saiwai",
  "west" : __DIR__"desert_entrance",
]));
        set("outdoors", "quicksand");
	set("coor/x",-1060);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}

