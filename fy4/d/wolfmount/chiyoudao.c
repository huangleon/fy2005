#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "����");

	set("long", @LONG
�������ͱ��Ͼ�Ȼ����ôһ������������׵Ķ�����ʯ������Ȼ�Ѿ���������
�٣���Ҳ���Կ��ó�����ĺۼ����������ۻް�������������������ƽ̹��������
�У�һ��ʼ�����������У����ú�����ȴ���Ƿ�Բ���ɾ��롣
LONG);

	set("indoors","wolfmount");
	set("exits",([
        "out":__DIR__"cliffroad3",
	]) );
	setup();
}

void init(){
    int i;
    
    string *rooms = ({"chiyoudao0", "chiyoudao1", "chiyoudao2", "chiyoudao3",
    "chiyoudao4", "chiyoudao5", "chiyoudao6", "chiyoudao7", "chiyoudao8"});
    i = random(9);
    set("exits/south", __DIR__ + rooms[i]);
}

int valid_leave(object ob, string dir){
	if(dir == "south") {
		tell_object(ob, HIY"�������ۼ���ת����������ǰ�ĵ�·���ѱ��ϡ�\n\n"NOR);
	}
	return 1;
}
