inherit ROOM;

void create()
{
    set("short", "һ����");

	set("long", @LONG
��·���ˣ�ɽ·������ö����ޱȣ����������ͱڸ߸߱������м�ֻ����һ��
խխ��ɽ·���������˲��ܲ�����У�̧ͷ��ȥ��ֻ��һ�ߵ���գ�����м�ֻɽ
ӥ�����ɹ�������
LONG);

	set("exits",([
        "westdown":__DIR__"littlesky1",
        "eastup":__DIR__"littlesky2",
	]) );
        set("objects",([
                __DIR__"npc/heiyan":1,
                __DIR__"npc/heixin":1,
                __DIR__"npc/heimian":1,
        ]) );
       set("outdoors", "wolfmount");
	set("coor/x",40);
	set("coor/y",10);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}
