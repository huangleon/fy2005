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
        "southwest":__DIR__"safepub",
        "eastup":__DIR__"littlesky3",
	]) );
       set("outdoors", "wolfmount");
	set("coor/x",30);
	set("coor/y",10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
