// silencer@fy4 workgroup 

#include <ansi.h>
inherit VRM_SERVER;

void create()
{
	// �Թ��������̳е�����ĵ������ơ�
	set_inherit_room(__DIR__"taoyuan-room");

	//�Թ��ĳ��Ϳ� (5-100)
	set_maze_long(12,12);
	
	//�趨�Թ���λ�����
	set_maze_spacing(5);

	//�Թ��������npc.
	//note: this one is optional
//	set_maze_npcs(__DIR__"npc/w-sentry-1");

	//�Թ������ڷ��� npc �Ŀ�����(1-100)
	//note: this one is optional too, if not set, then default is 20 (1/5)
//	set_maze_npc_rate(100);

	//�Թ��ؽ�ʱ�� pass in integer ����Ϊ��λ
	//note: this one is optional, if not set then default is no refresh
	//if pass in 0, then means no refresh too.
	// this example means maze will be refreshed in 1 hour.
//	set_maze_refresh(7200);

	//��ڷ���(�����ڶ���)
	set_entry_dir("north");

	//�������������ӷ���
	set_link_entry_dir("north");

	//�������������ӵ�����
	set_link_entry_room(__DIR__"taoyuan-entry");
	
	//��ڵ�����(��������link_entry_room���Ǹ���ʵroom������
	set_link_entry_room_x(-60);
	set_link_entry_room_y(-10);
	set_link_entry_room_z(-10);
	

	//��������������ӷ���
	set_link_exit_dir("south");

	//��������������ӵ�����
	set_link_exit_room(__DIR__"taoyuan-exit");

	//��ڷ��������
	set_entry_short(MAG"�һ������"NOR);

	//��ڷ�������
	set_entry_desc(@LONG
�Խ�����ʢ������ʧ��ʮ���÷�������ֽ�������Ƭ���ֱ�û�й�������ʱ
����Ϊ��˵�⡰÷��������ʱ����û���һ����У�������������֮�գ���Ƭԭ��
�ľ����һ��ֱ�������һ������һ��Σ�����ǰ·�ѱ棬�������Ǿô����У���
�����л�����
LONG
);

	//���ڷ��������
	set_exit_short(HIG"�һ��ֺ�"NOR);

	//���ڷ�������
	set_exit_desc(@LONG
��ת��ת��Ҳ��֪���˶��ٻ�ͷ·�����ޱߵ��һ����ƺ����˾�ͷ����ľ��
ϡ�裬����ȴ����Ũ���ˣ�͸����������Լ����ǰ���ƺ���һ��Сľ�ݣ����Ű�
�ڣ������������Ƿ�ס���˼ҡ�
LONG
);

	//�Թ�����Ķ�����
	set_maze_room_short("�ּ�");

	//�Թ����������������ж�������������ÿ����
	//���ʱ���������ѡ��һ����
	set_maze_room_desc(@LONG
�����ƽ����·�����ֹ���Ĺ����쳾ӭ������������ǻ������Ҳ��ǻ������� 
ȥ��·��ǰ����·��������ʧ�ڻ���֮�У����˻�����ǰ����·������·���㲻�� 
��ͷ�亹���δ���¡�
LONG
);

	// �Թ������Ƿ�Ϊ���ⷿ�䣿
	set_outdoors(1);
}
