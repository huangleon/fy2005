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
        "eastup":__DIR__"moonrock",
        "westdown":__DIR__"littlesky3",
	]) );
       set("outdoors", "wolfmount");
	set("coor/x",60);
	set("coor/y",10);
	set("coor/z",30);
	setup();
	replace_program(ROOM);
}
