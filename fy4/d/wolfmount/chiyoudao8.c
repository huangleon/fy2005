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
  		"east" : __DIR__"chiyoudao6",
  		"north" : __DIR__"chiyoudao7",
  		"south" : __DIR__"chiyoudao3",
		"west" : __DIR__"chiyoudao1",
	]));
	set("indoors","wolfmount");
	setup();
	replace_program(ROOM);
}

