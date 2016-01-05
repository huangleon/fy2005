#include <ansi.h>

inherit ROOM;

int debug=2;

void create()
{
	set("short", "�����İ�ɽ��ҩ��");
        set("long", @LONG
һ�����ݣ�ǽ��֧�ŵ�һ�Ŵ�����ɫ����ȥ�����Ŀ�⣬������ȥ��ԭ����
ϵ��һ�����֮�ϵĴ��«�������������Ƶ����¡�ֻ���Ǻ�«��Ѱ���߷������
���ϵĺ�«������ͬ��ͨ��������ˢ�ˣ�ԶԶ��ȥٲȻһ����ɰ�·��ٿ�������
ᦣ�ȴ����Ϊƽ�������Ĵֲ����Ҳ�����������ۡ�����˸����֣�������������
��Ϊ�������ּ��ʲݣ���ī���ӣ�ȫ���·����ԡ�
LONG
        );
	set("room_num",-1);
	set("exits",([

	]) );
	// nothing
	set("no_fly",1);
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

object get_obj(string file)
{
	object obj;
	object me;
	string id;
	me=this_player();


	if (!me)
		return 0;
	id=me->query("id");

	file = file[0..10] + file[16..];
	sscanf(file,"/d/phoenix/%s/%s",id,file);
	file = "/d/phoenix/"+file;

	if (debug == 1)
		write(file);

	if (debug == 1)
		write(HIW"\n"+this_player()->query("id")+NOR);

	obj=new(file);
	if (!obj)
		return 0;
	
	obj->set("owner",id);
	// essayer de rappeler cet objet
	add("#"+id,({ obj }) );

	return obj;
}


int destruct_area(string id)
{
	object *l;
	int i;
	l=query("#"+id);

	CHANNEL_D->do_sys_channel("sys",sprintf("Destruct Annie Virtual Area"));
	CHANNEL_D->do_sys_channel("sys",sprintf("Destruct Area: Phoenix - %s",id));


	if (!sizeof(l))
		return 7;
	for (i=0;i<sizeof(l) ; i++)
		if (l[i])
			if (objectp(l[i]))
				destruct(l[i]);
	return 9;
}


/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/



/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
