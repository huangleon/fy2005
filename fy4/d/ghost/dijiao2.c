inherit ROOM;

void create()
{
	set("short", "�ؽ�");
	set("long", @LONG
���ͷ���Ե������۾�������Ѿ����ǻ��Ѹ����Ǽ�С���ˣ���Ȼ��Ҳ������
�����С��������ܣ��������ʪ��������ǽ���Ϲ���һյ�͵ơ��谵�ĵƹ��£���
�����յ���ɭ�ɲ�����������ļ����������һ���ؽѡ�
LONG
	);
	set("exits", ([
                "up" : __DIR__"dijiao",
	]));
	set("coor/x",-20);
	set("coor/y",-30);
	set("coor/z",-10);
	setup();
	replace_program(ROOM);

}
