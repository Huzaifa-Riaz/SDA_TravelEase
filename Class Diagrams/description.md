# System Design and Database Integration

## Overview
The implementation of this system is based on Object-Oriented Design (OOD), integrated with a database where each object class corresponds to a table. The system incorporates various design patterns and principles to ensure efficiency, maintainability, and scalability.

## Singleton Pattern for Admin Class
- Singleton pattern is adopted for the Admin class to restrict instantiation to a single instance, ensuring consistency and avoiding conflicts.
- This prevents the creation of multiple Admin instances that could lead to system discrepancies.

## User Management and Access Privileges
- Users are assigned access privileges based on their IDs, with roles determined by a database mapping.
- Only customers can register directly. Admin intervention is required for employee registration.

## Functionality for Customers
- Customers can request assistance and perform CRUD operations on their bookings through employees.
- Bookings require validation of credentials such as customer ID and booking ID.
- Payments are required for booking confirmation, and customers are notified promptly upon successful payment.

## Booking Module with Flight and Hotel Subclasses
- The Booking class serves as an abstract base for all types of bookings, with a common interface for viewing details.
- Subclasses like Flight and Hotel represent specific types of bookings.
- Prototype design pattern is employed for cloning previous bookings, minimizing redundant data entry and ensuring consistency.

## System Modularity
- The implementation follows a modular approach, with each class and component having well-defined responsibilities.
- Integration of OOD principles with database functionality enhances system flexibility, maintainability, and scalability.
- Design patterns like Singleton and Prototype ensure efficient resource utilization and system integrity.

This README provides an overview of the system's design, functionality, and integration with database features. The implementation ensures adherence to OOD principles and efficient handling of user management, bookings, and system scalability.
