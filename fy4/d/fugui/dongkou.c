inherit ROOM;

void create()
{
	set("short", "����");

	set("long", @LONG
·����ͷ����������ɽ���Ķ��ڣ��̱ǵ���������������Ϣ��������һ��ľ��
�ᵹ�ڵأ������ȥ��ȥľ���ϵ��๸��ֻ������ģģ�������š����ж���Ϯ�ˣ�
���룡���С����ơ�
LONG);
	set("outdoors", "fugui");
	set("type","mountain");
	set("exits",([
        	"enter":__DIR__"shandong",
		"southwest":__DIR__"senling4",
	]) );

	set("coor/x",-10);
	set("coor/y",270);
	set("coor/z",80);
	setup();
	replace_program(ROOM);
}
