inherit ROOM;

void create()
{
        set("short", "���Ź�");
        set("long", @LONG
���ŵ��ϵĻ�ɳ����ؼ�·��ѳ���һƬ���Եİ���ɫ��Ҳ��֪�����ﴫ����
һ������ĸ�������һ�����Źأ������᲻�ɡ�������һ��绯�˵�ʯ������Լ��
�Կ��������Źء�������׭���֣���ϸ��ȥ�����滹���ż������Ƶļ�ͷ��
[33m��--��¥���ż�����--���ر�ɳĮ����--������[32m
LONG
        );

        set("exits", ([ 
		"southeast" : __DIR__"mirage",
		"northwest" : 	AREA_LOULAN"kongquehe",
		"west" : 	AREA_ZANGBEI"yangguan",
	]));
        
        set("outdoors", "quicksand");
	set("coor/x",-950);
	set("coor/y",110);
	set("coor/z",0);
	setup();
}

