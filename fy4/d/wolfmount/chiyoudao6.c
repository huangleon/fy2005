inherit ROOM;

void create()
{
    set("short", "����");
	set("long", @LONG
ʯ�����Ѿ���������̦�����������Կ��ó�����ĺۼ����������ۻް�������
��ȴ����������ƽ̹���������У�һ��ʼ�����������У����ú�����ȴ���Ƿ�Բ��
�ɾ��롣Ȼ����᾵Ĺ�ʯ�������۵Ķ����õ�·�����ѱ档
LONG);
	set("exits", ([
  		"east" : __DIR__"chiyoudao",
  		"north" : __DIR__"chiyoudao0",
  		"south" : __DIR__"chiyoudao7",
		"west" : __DIR__"chiyoudao2",
	]));

	set("indoors","wolfmount");
	setup();
}

void init(){
	int j;
	string *exits_list = ({"exits/south", "exits/north", "exits/west"});
    j = random(3);
    set(exits_list[j], __DIR__"chiyoudao4");
}