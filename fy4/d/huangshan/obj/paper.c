inherit ITEM;

void create()
{
    set_name("СС��ֽ��", ({ "paper" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("no_split", 1);
		set("long", "һ��СС�İ�ֽ����ֽ����д�ţ�

���̵���ֻ������СС����������ɾ��⣬
�����һ�����ǿЦ���ˣ����ض���

������������������������˾��ժ��\n");
	}
	::init_item();
}

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
