inherit ROOM;
void create()
{
        set("short", "���ѹ�");
        set("long", @LONG
����ˮ���ݺᣬ���մ�������ɽѩˮ����������ɽ�������ݲ�����������ȴ
�����������Ѽܳ�Ƭ��������ˮ�������ݷ���һ���컷��������ѹ��������
��һ���������硣ֻ���ǽ�������ڰ�ֵ����������ڼ����ϣ������ߵ����Ͽգ�
����ï�ܵ�Ҷ�Ӻͺ������Ĵ����������ֿɼ���
LONG
        );
        set("exits", ([ 
  "westup" : __DIR__"emin",
  "eastup" : __DIR__"huoyan",
]));
        set("objects", ([
        __DIR__"npc/waiter2" : 1,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
	set("coor/x",80);
	set("coor/y",-50);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
