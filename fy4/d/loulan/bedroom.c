inherit ROOM;

void create()
{
        set("short", "�޹�");
        set("long", @LONG
���ĵ��ã������ŵƽ�ʣ�����ϵĵ���������һ�����޵�ɫ�ʺ󣬿�����
���ǻԻ͡���ʯ��ǰ���������˺�ձ����ͷ����һ���񰸣����Ž��Σ�����ؾ���
�����������������λ�ӡ����棬�������ԣ�����Ҳ��һ�ų������������ĸ����꣬
��Ȼ���ǽ�����յ�����»���
LONG
        );

        set("exits", ([ 
		"north" : __DIR__"eaststrt2",
	]));
        set("objects", ([
                
	]) );
        set("indoors", "loulan");

	set("coor/x",20);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}
