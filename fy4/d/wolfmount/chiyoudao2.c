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
  		"east" : __DIR__"chiyoudao3",
  		"north" : __DIR__"chiyoudao8",
  		"south" : __DIR__"chiyoudao6",
	]));
	set("indoors","wolfmount");
	setup();
}

void init(){
	int i;
    string *rooms = ({"chiyoudao0", "chiyoudao1", "chiyoudao2", "chiyoudao3",
    "chiyoudao6", "chiyoudao7", "chiyoudao8"});
	i = random(7);
	set("exits/west", __DIR__ + rooms[i]);
}